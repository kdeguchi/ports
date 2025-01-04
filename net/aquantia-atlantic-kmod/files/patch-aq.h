--- aq.h.orig	2024-11-19 02:33:57 UTC
+++ aq.h
@@ -0,0 +1,674 @@
+/*
+ * aQuantia Corporation Network Driver
+ * Copyright (C) 2014-2017 aQuantia Corporation. All rights reserved
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *
+ *   (1) Redistributions of source code must retain the above
+ *   copyright notice, this list of conditions and the following
+ *   disclaimer.
+ *
+ *   (2) Redistributions in binary form must reproduce the above
+ *   copyright notice, this list of conditions and the following
+ *   disclaimer in the documentation and/or other materials provided
+ *   with the distribution.
+ *
+ *   (3)The name of the author may not be used to endorse or promote
+ *   products derived from this software without specific prior
+ *   written permission.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS
+ * OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
+ * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
+ * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
+ * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
+ * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
+ * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
+ * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
+ * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
+ * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
+ * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
+ */
+
+#ifndef _AQ_H_
+#define _AQ_H_
+
+#include <sys/param.h>
+#include <sys/bitstring.h>
+#include <sys/bus.h>
+#include <sys/cdefs.h>
+#include <sys/endian.h>
+#include <sys/kernel.h>
+#include <sys/socket.h>
+
+#include <machine/cpufunc.h>
+
+#include <net/ethernet.h>
+#include <net/if.h>
+#include <net/if_dl.h>
+#include <net/if_media.h>
+#include <net/if_var.h>
+#include <net/iflib.h>
+
+#include <netinet/in.h>
+
+#define ETH_MAC_LEN 6
+
+#define s8       __int8_t
+#define u8       __uint8_t
+#define u16      __uint16_t
+#define s16      __int16_t
+#define u32      __uint32_t
+#define u64      __uint64_t
+#define s64      __int64_t
+#define s32      int
+
+#define ETIME ETIMEDOUT
+#define	EOK 0
+
+#define BIT(nr) (1UL << (nr))
+
+#define usec_delay(x) DELAY(x)
+
+#ifndef msec_delay
+#define msec_delay(x) DELAY(x*1000)
+#define msec_delay_irq(x) DELAY(x*1000)
+#endif
+
+#define AQ_HW_WAIT_FOR(_B_, _US_, _N_) \
+	do { \
+		unsigned int i; \
+		for (i = _N_; (!(_B_)) && i; --i) { \
+			usec_delay(_US_); \
+		} \
+		if (i == 0) { \
+			err = -1; \
+		} \
+	} while (0)
+
+
+#define LODWORD(a) ((DWORD)(a))
+#define LOWORD(a) ((uint16_t)(a))
+#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
+
+#define AQ_VER        "0.0.5"
+
+#define	AQ_WRITE_REG(hw, reg, value) \
+	writel(((hw)->hw_addr + (reg)), htole32(value))
+#define	AQ_READ_REG(hw, reg) \
+	le32toh(readl((hw)->hw_addr + reg))
+
+#define	AQ_WRITE_REG_BIT(hw, reg, msk, shift, value) \
+	do { \
+		if (msk ^ ~0) { \
+			uint32_t reg_old, reg_new = 0; \
+			reg_old = AQ_READ_REG(hw, reg); \
+			reg_new = (reg_old & (~msk)) | (value << shift); \
+			if (reg_old != reg_new) \
+				AQ_WRITE_REG(hw, reg, reg_new); \
+		} else { \
+			AQ_WRITE_REG(hw, reg, value); \
+		} \
+	} while(0);
+
+
+#define	AQ_READ_REG_BIT(a, reg, msk, shift) \
+	((AQ_READ_REG(a, reg) & msk) >> shift)
+
+#define AQ_HW_FLUSH() { (void)AQ_READ_REG(hw, 0x10); }
+
+#define aq_hw_write_reg_bit AQ_WRITE_REG_BIT
+
+#define aq_hw_write_reg AQ_WRITE_REG
+
+/* Statistics  */
+typedef struct aq_hw_stats_s {
+	uint32_t	uprc;
+	uint32_t	mprc;
+	uint32_t	bprc;
+	uint32_t	erpt;
+	uint32_t	uptc;
+	uint32_t	mptc;
+	uint32_t	bptc;
+	uint32_t	erpr;
+	uint32_t	mbtc;
+	uint32_t	bbtc;
+	uint32_t	mbrc;
+	uint32_t	bbrc;
+	uint32_t	ubrc;
+	uint32_t	ubtc;
+	uint32_t	ptc;
+	uint32_t	prc;
+	uint32_t	dpc;
+	uint32_t	cprc;
+} __packed aq_hw_stats_t;
+
+union ip_addr {
+	struct {
+		uint8_t addr[16];
+	} v6;
+	struct {
+		uint8_t padding[12];
+		uint8_t addr[4];
+	} v4;
+} __packed;
+
+typedef struct aq_hw_fw_mbox {
+	uint32_t	version;
+	uint32_t	transaction_id;
+	int		error;
+	aq_hw_stats_t	stats;
+} __packed aq_hw_fw_mbox_t;
+
+typedef struct {
+	union {
+		struct {
+			uint16_t	build_number;
+			uint8_t		minor_version;
+			uint8_t		major_version;
+		};
+		uint32_t	raw;
+	};
+} aq_hw_fw_version;
+
+typedef enum {
+	aq_irq_invalid = 0,
+	aq_irq_legacy,
+	aq_irq_msi,
+	aq_irq_msix,
+} aq_hw_irq_type_t;
+
+typedef struct aq_hw_fc_info {
+	bool		fc_rx;
+	bool		fc_tx;
+} aq_hw_fc_info_t;
+
+enum aq_hw_fw_mpi_state_e {
+	MPI_DEINIT = 0,
+	MPI_RESET = 1,
+	MPI_INIT = 2,
+	MPI_POWER = 4,
+};
+
+typedef enum {
+	aq_fw_none = 0,
+	aq_fw_100M = 1 << 0,
+	aq_fw_1G = 1 << 1,
+	aq_fw_2G5 = 1 << 2,
+	aq_fw_5G = 1 << 3,
+	aq_fw_10G = 1 << 4,
+} aq_fw_link_speed_t;
+
+typedef enum {
+    aq_fw_fc_none  = 0,
+    aq_fw_fc_ENABLE_RX = BIT(0),
+    aq_fw_fc_ENABLE_TX = BIT(1),
+    aq_fw_fc_ENABLE_ALL = aq_fw_fc_ENABLE_RX | aq_fw_fc_ENABLE_TX,
+} aq_fw_link_fc_t;
+
+#define aq_hw_s aq_hw
+typedef struct aq_hw aq_hw_t;
+
+typedef struct aq_firmware_ops {
+	int (*reset)(aq_hw_t *hw);
+
+	int (*set_mode)(aq_hw_t *hw, enum aq_hw_fw_mpi_state_e mode,
+	    aq_fw_link_speed_t speed);
+	int (*get_mode)(aq_hw_t *hw, enum aq_hw_fw_mpi_state_e *mode,
+	    aq_fw_link_speed_t *speed, aq_fw_link_fc_t *fc);
+
+	int (*get_mac_addr)(aq_hw_t *hw, uint8_t *mac_addr);
+	int (*get_stats)(aq_hw_t *hw, aq_hw_stats_t *stats);
+
+	int (*led_control)(struct aq_hw *hal, uint32_t mode);
+} aq_fw_ops_t;
+
+struct aq_hw {
+	void		*aq_dev;
+	uint8_t		*hw_addr;
+	uint32_t	regs_size;
+
+	uint8_t		mac_addr[ETH_MAC_LEN];
+
+	aq_hw_irq_type_t irq_type;
+
+	aq_hw_fc_info_t	fc;
+	uint16_t	link_rate;
+
+	uint16_t	device_id;
+	uint16_t	subsystem_vendor_id;
+	uint16_t	subsystem_device_id;
+	uint16_t	vendor_id;
+	uint8_t		revision_id;
+
+	/* Interrupt Moderation value */
+	int		itr;
+
+	/* Firmware-related stuff */
+	aq_hw_fw_version fw_version;
+	aq_fw_ops_t	*fw_ops;
+	bool		rbl_enabled;
+	bool		fast_start_enabled;
+	bool		flash_present;
+	uint32_t	chip_features;
+	uint64_t	fw_caps;
+
+	bool		lro_enabled;
+
+	uint32_t	mbox_addr;
+	aq_hw_fw_mbox_t	mbox;
+};
+
+#define AQ_HW_MAC      0
+#define AQ_HW_MAC_MIN  1
+#define AQ_HW_MAC_MAX  33
+
+#define HW_ATL_B0_MIN_RXD 32
+#define HW_ATL_B0_MIN_TXD 32
+#define HW_ATL_B0_MAX_RXD 4096 /* in fact up to 8184, but closest to power of 2 */
+#define HW_ATL_B0_MAX_TXD 4096 /* in fact up to 8184, but closest to power of 2 */
+
+#define HW_ATL_B0_MTU_JUMBO	16352
+#define HW_ATL_B0_TSO_SIZE	(160 * 1024)
+#define HW_ATL_B0_RINGS_MAX	32
+#define HW_ATL_B0_LRO_RXD_MAX	16
+
+#define AQ_HW_MPI_STATE_MSK	0x00ff
+#define AQ_HW_MPI_STATE_SHIFT	0
+
+#define AQ_HW_MPI_CONTROL_ADR	0x0368
+#define AQ_HW_MPI_STATE_ADR	0x036c
+
+#define HW_ATL_RSS_INDIRECTION_TABLE_MAX	64
+#define HW_ATL_RSS_HASHKEY_SIZE			40
+
+/* PCI core control register */
+#define AQ_HW_PCI_REG_CONTROL_6_ADR		0x1014
+/* tx dma total request limit */
+#define AQ_HW_TX_DMA_TOTAL_REQ_LIMIT_ADR	0x00007b20
+
+#define AQ_HW_TXBUF_MAX		160
+#define AQ_HW_RXBUF_MAX		320
+
+#define L2_FILTER_ACTION_DISCARD	0x0
+#define L2_FILTER_ACTION_HOST		0x1
+
+#define AQ_HW_UCP_0X370_REG	0x370
+#define AQ_HW_CHIP_MIPS		0x00000001
+#define AQ_HW_CHIP_TPO2		0x00000002
+#define AQ_HW_CHIP_RPF2		0x00000004
+#define AQ_HW_CHIP_MPI_AQ	0x00000010
+#define AQ_HW_CHIP_REVISION_A0	0x01000000
+#define AQ_HW_CHIP_REVISION_B0	0x02000000
+#define AQ_HW_CHIP_REVISION_B1	0x04000000
+#define IS_CHIP_FEATURE(HW, _F_) \
+	(AQ_HW_CHIP_##_F_ & (HW)->chip_features)
+
+#define AQ_HW_FW_VER_EXPECTED	0x01050006
+
+#define	AQ_RX_RSS_TYPE_NONE	0x0
+#define	AQ_RX_RSS_TYPE_IPV4	0x2
+#define	AQ_RX_RSS_TYPE_IPV6	0x3
+#define	AQ_RX_RSS_TYPE_IPV4_TCP	0x4
+#define	AQ_RX_RSS_TYPE_IPV6_TCP	0x5
+#define	AQ_RX_RSS_TYPE_IPV4_UDP	0x6
+#define	AQ_RX_RSS_TYPE_IPV6_UDP	0x7
+
+enum hw_atl_rx_action_with_traffic {
+	HW_ATL_RX_DISCARD,
+	HW_ATL_RX_HOST,
+	HW_ATL_RX_MNGMNT,
+	HW_ATL_RX_HOST_AND_MNGMNT,
+	HW_ATL_RX_WOL
+};
+
+typedef struct aq_rx_filter_vlan {
+	uint8_t		enable;
+	uint8_t		location;
+	uint16_t	vlan_id;
+	uint8_t		queue;
+} aq_rx_filter_vlan_t;
+
+#define AQ_HW_VLAN_MAX_FILTERS         16U
+#define AQ_HW_ETYPE_MAX_FILTERS        16U
+
+typedef struct {
+	uint8_t		enable;
+	int8_t		queue;
+	uint8_t		location;
+	uint8_t		user_priority_en;
+	uint8_t		user_priority;
+	uint16_t	ethertype;
+} aq_rx_filter_l2_t;
+
+enum hw_atl_rx_ctrl_registers_l2 {
+	HW_ATL_RX_ENABLE_UNICAST_MNGNT_QUEUE_L2 = BIT(19),
+	HW_ATL_RX_ENABLE_UNICAST_FLTR_L2        = BIT(31)
+};
+
+struct aq_rx_filter_l3l4 {
+	uint32_t cmd;
+	uint8_t location;
+	uint32_t ip_dst[4];
+	uint32_t ip_src[4];
+	uint16_t p_dst;
+	uint16_t p_src;
+	bool is_ipv6;
+};
+
+enum hw_atl_rx_protocol_value_l3l4 {
+	HW_ATL_RX_TCP,
+	HW_ATL_RX_UDP,
+	HW_ATL_RX_SCTP,
+	HW_ATL_RX_ICMP
+};
+
+enum hw_atl_rx_ctrl_registers_l3l4 {
+	HW_ATL_RX_ENABLE_MNGMNT_QUEUE_L3L4 = BIT(22),
+	HW_ATL_RX_ENABLE_QUEUE_L3L4        = BIT(23),
+	HW_ATL_RX_ENABLE_ARP_FLTR_L3       = BIT(24),
+	HW_ATL_RX_ENABLE_CMP_PROT_L4       = BIT(25),
+	HW_ATL_RX_ENABLE_CMP_DEST_PORT_L4  = BIT(26),
+	HW_ATL_RX_ENABLE_CMP_SRC_PORT_L4   = BIT(27),
+	HW_ATL_RX_ENABLE_CMP_DEST_ADDR_L3  = BIT(28),
+	HW_ATL_RX_ENABLE_CMP_SRC_ADDR_L3   = BIT(29),
+	HW_ATL_RX_ENABLE_L3_IPv6           = BIT(30),
+	HW_ATL_RX_ENABLE_FLTR_L3L4         = BIT(31)
+};
+
+#define HW_ATL_RX_BOFFSET_PROT_FL3L4      0
+#define HW_ATL_RX_BOFFSET_QUEUE_FL3L4     8
+#define HW_ATL_RX_BOFFSET_ACTION_FL3F4    16
+
+#define HW_ATL_RX_CNT_REG_ADDR_IPV6       4
+
+#define HW_ATL_GET_REG_LOCATION_FL3L4(location) \
+	((location) - AQ_RX_FIRST_LOC_FL3L4)
+
+int aq_hw_get_mac_permanent(aq_hw_t *, uint8_t *);
+
+int aq_hw_mac_addr_set(aq_hw_t *, uint8_t *, uint8_t);
+
+/* link speed in mbps. "0" - no link detected */
+int aq_hw_get_link_state(aq_hw_t *, uint32_t *, aq_hw_fc_info_t *);
+int aq_hw_set_link_speed(aq_hw_t *, uint32_t);
+int aq_hw_fw_downld_dwords(aq_hw_t *, uint32_t, uint32_t *, uint32_t);
+int aq_hw_reset(aq_hw_t *);
+int aq_hw_mpi_create(aq_hw_t *);
+int aq_hw_mpi_read_stats(aq_hw_t *, aq_hw_fw_mbox_t *);
+int aq_hw_init(aq_hw_t *, uint8_t *, uint8_t, bool);
+int aq_hw_start(aq_hw_t *);
+int aq_hw_interrupt_moderation_set(aq_hw_t *);
+int aq_hw_get_fw_version(aq_hw_t *, uint32_t *);
+int aq_hw_deinit(aq_hw_t *);
+void aq_hw_set_promisc(aq_hw_t *, bool, bool, bool);
+int aq_hw_set_power(aq_hw_t *, unsigned int);
+int aq_hw_err_from_flags(aq_hw_t *);
+
+int hw_atl_b0_hw_vlan_promisc_set(aq_hw_t *, bool);
+int hw_atl_b0_hw_vlan_set(aq_hw_t *, aq_rx_filter_vlan_t *);
+
+/* FIXME fix these monstrosities */
+int aq_hw_rss_hash_set(aq_hw_t *, uint8_t rss_key[HW_ATL_RSS_HASHKEY_SIZE]);
+int aq_hw_rss_hash_get(aq_hw_t *, uint8_t rss_key[HW_ATL_RSS_HASHKEY_SIZE]);
+int aq_hw_rss_set(aq_hw_t *, uint8_t rss_table[HW_ATL_RSS_INDIRECTION_TABLE_MAX]);
+int aq_hw_udp_rss_enable(aq_hw_t *, bool);
+
+#define aq_fw_speed_auto (aq_fw_100M | aq_fw_1G | aq_fw_2G5 | aq_fw_5G | aq_fw_10G)
+
+int aq_fw_reset(aq_hw_t *hw);
+int aq_fw_ops_init(aq_hw_t *hw);
+
+enum aq_media_type {
+	AQ_MEDIA_TYPE_UNKNOWN = 0,
+	AQ_MEDIA_TYPE_FIBRE,
+	AQ_MEDIA_TYPE_TP,
+};
+
+#define	AQ_LINK_UNKNOWN	0x00000000
+#define	AQ_LINK_100M	0x00000001
+#define	AQ_LINK_1G	0x00000002
+#define	AQ_LINK_2G5	0x00000004
+#define	AQ_LINK_5G	0x00000008
+#define	AQ_LINK_10G	0x00000010
+
+#define	AQ_LINK_ALL	\
+	(AQ_LINK_100M | AQ_LINK_1G | AQ_LINK_2G5 | AQ_LINK_5G | AQ_LINK_10G)
+
+typedef struct aq_stats_s {
+	uint64_t	prc;
+	uint64_t	uprc;
+	uint64_t	mprc;
+	uint64_t	bprc;
+	uint64_t	cprc;
+	uint64_t	erpr;
+	uint64_t	dpc;
+	uint64_t	brc;
+	uint64_t	ubrc;
+	uint64_t	mbrc;
+	uint64_t	bbrc;
+
+	uint64_t	ptc;
+	uint64_t	uptc;
+	uint64_t	mptc;
+	uint64_t	bptc;
+	uint64_t	erpt;
+	uint64_t	btc;
+	uint64_t	ubtc;
+	uint64_t	mbtc;
+	uint64_t	bbtc;
+} aq_stats_t;
+
+typedef enum {
+    AQ_DEV_STATE_UNLOAD,
+    AQ_DEV_STATE_PCI_STOP,
+    AQ_DEV_STATE_DOWN,
+    AQ_DEV_STATE_UP,
+} aq_dev_state_t;
+
+struct aq_rx_filters {
+	unsigned int	rule_cnt;
+	aq_rx_filter_vlan_t vlan_filters[AQ_HW_VLAN_MAX_FILTERS];
+	aq_rx_filter_l2_t etype_filters[AQ_HW_ETYPE_MAX_FILTERS];
+};
+
+typedef struct {
+	SLIST_ENTRY(aq_vlan_tag) next;
+	uint16_t	tag;
+} aq_vlan_tag_t;
+
+typedef struct aq_ring aq_ring_t;
+
+typedef struct aq_dev {
+	device_t		dev;
+	if_ctx_t		ctx;
+	if_softc_ctx_t		scctx;
+	if_shared_ctx_t		sctx;
+	struct ifmedia		*media;
+
+	aq_hw_t			hw;
+
+	enum aq_media_type	media_type;
+	uint32_t		link_speeds;
+	uint32_t		chip_features;
+	uint32_t		mbox_addr;
+	uint8_t			mac_addr[ETHER_ADDR_LEN];
+	uint64_t		admin_ticks;
+	struct if_irq		irq;
+	int			msix;
+
+	int			mmio_rid;
+	struct resource *	mmio_res;
+	bus_space_tag_t		mmio_tag;
+	bus_space_handle_t	mmio_handle;
+	bus_size_t		mmio_size;
+
+	aq_ring_t		*tx_rings[HW_ATL_B0_RINGS_MAX];
+	aq_ring_t		*rx_rings[HW_ATL_B0_RINGS_MAX];
+	uint32_t		tx_rings_count;
+	uint32_t		rx_rings_count;
+	bool			linkup;
+	int			media_active;
+
+	aq_hw_stats_t		last_stats;
+	aq_stats_t		curr_stats;
+
+	bitstr_t		*vlan_tags;
+	int			mcnt;
+
+	uint8_t			rss_key[HW_ATL_RSS_HASHKEY_SIZE];
+	uint8_t			rss_table[HW_ATL_RSS_INDIRECTION_TABLE_MAX];
+} aq_dev_t;
+
+int aq_update_hw_stats(aq_dev_t *aq_dev);
+void aq_initmedia(aq_dev_t *aq_dev);
+int aq_linkstat_isr(void *arg);
+int aq_isr_rx(void *arg);
+void aq_mediastatus_update(aq_dev_t *, uint32_t, const aq_hw_fc_info_t *);
+void aq_mediastatus(if_t, struct ifmediareq *);
+int aq_mediachange(if_t);
+void aq_if_update_admin_status(if_ctx_t);
+
+#define REFILL_THRESHOLD 128
+
+typedef volatile struct {
+    uint32_t	rss_type:4;
+    uint32_t	pkt_type:8;
+    uint32_t	rdm_err:1;
+    uint32_t	rsvd:6;
+    uint32_t	rx_cntl:2;
+    uint32_t	sph:1;
+    uint32_t	hdr_len:10;
+    uint32_t	rss_hash;
+    uint16_t	dd:1;
+    uint16_t	eop:1;
+    uint16_t	rx_stat:4;
+    uint16_t	rx_estat:6;
+    uint16_t	rsc_cnt:4;
+    uint16_t	pkt_len;
+    uint16_t	next_desp;
+    uint16_t	vlan;
+} __packed aq_rx_wb_t;
+
+/* Hardware RX descriptor */
+typedef volatile struct {
+	union {
+		/* HW RX descriptor */
+		struct {
+			uint64_t	buf_addr;
+			uint64_t	hdr_addr;
+		} __packed read;
+		/* HW RX descriptor writeback */
+		aq_rx_wb_t	wb;
+	};
+} __packed aq_rx_desc_t;
+
+/* Hardware TX descriptor */
+typedef volatile struct {
+	uint64_t buf_addr;
+	union {
+		struct {
+			uint32_t	type:3;
+			uint32_t	:1;
+			uint32_t	len:16;
+			uint32_t	dd:1;
+			uint32_t	eop:1;
+			uint32_t	cmd:8;
+			uint32_t	:14;
+			uint32_t	ct_idx:1;
+			uint32_t	ct_en:1;
+			uint32_t	pay_len:18;
+		} __packed;
+		uint64_t flags;
+	};
+} __packed aq_tx_desc_t;
+
+enum {
+	tx_desc_type_desc = 1,
+	tx_desc_type_ctx = 2,
+};
+
+enum {
+	tx_desc_cmd_vlan = 1,
+	tx_desc_cmd_fcs = 2,
+	tx_desc_cmd_ipv4 = 4,
+	tx_desc_cmd_l4cs = 8,
+	tx_desc_cmd_lso = 0x10,
+	tx_desc_cmd_wb = 0x20,
+};
+
+/* Hardware TX context descriptor */
+typedef volatile union {
+	struct {
+		uint64_t	flags1;
+		uint64_t	flags2;
+	} __packed;
+	struct {
+		uint64_t	:40;
+		uint32_t	tun_len:8;
+		uint32_t	out_len:16;
+		uint32_t	type:3;
+		uint32_t	idx:1;
+		uint32_t	vlan_tag:16;
+		uint32_t	cmd:4;
+		uint32_t	l2_len:7;
+		uint32_t	l3_len:9;
+		uint32_t	l4_len:8;
+		uint32_t	mss_len:16;
+	} __packed;
+} __packed aq_txc_desc_t;
+
+typedef struct {
+	uint64_t rx_pkts;
+	uint64_t rx_bytes;
+	uint64_t jumbo_pkts;
+	uint64_t rx_err;
+	uint64_t irq;
+
+	uint64_t tx_pkts;
+	uint64_t tx_bytes;
+	uint64_t tx_drops;
+	uint64_t tx_queue_full;
+} aq_ring_stats_t;
+
+struct aq_ring {
+	aq_dev_t	*dev;
+	int		index;
+
+	struct if_irq	irq;
+	int		msix;
+	/* RX */
+	qidx_t		rx_size;
+	int		rx_max_frame_size;
+	void		*rx_desc_area_ptr;
+	aq_rx_desc_t	*rx_descs;
+	uint64_t	rx_descs_phys;
+
+	/* TX */
+	int		tx_head, tx_tail;
+	qidx_t		tx_size;
+	void		*tx_desc_area_ptr;
+	aq_tx_desc_t	*tx_descs;
+	uint64_t	tx_descs_phys;
+
+	aq_ring_stats_t	stats;
+};
+
+int aq_ring_rx_init(aq_hw_t *, aq_ring_t *);
+int aq_ring_tx_init(aq_hw_t *, aq_ring_t *);
+
+int aq_ring_tx_start(aq_hw_t *, aq_ring_t *);
+int aq_ring_tx_stop(aq_hw_t *, aq_ring_t *);
+int aq_ring_rx_start(aq_hw_t *, aq_ring_t *);
+int aq_ring_rx_stop(aq_hw_t *, aq_ring_t *);
+
+int aq_ring_tx_tail_update(aq_hw_t *, aq_ring_t *, uint32_t);
+
+extern struct if_txrx aq_txrx;
+int aq_intr(void *);
+
+int aq_hw_ver_match(const aq_hw_fw_version *, const aq_hw_fw_version *);
+
+#endif	/* !_AQ_H_ */
