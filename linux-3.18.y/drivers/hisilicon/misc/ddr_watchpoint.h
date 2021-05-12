#ifndef DDR_WATCHPOINT_H
#define DDR_WATCHPOINT_H

#define WADDR_TRAMPLE_BASE				0xF8A36000
#define WADDR_TRAMPLE_END				WADDR_TRAMPLE_BASE + 0x1000				

#define WADDR_TRAMPLE_CLKGCFG				0x0
#define WADDR_TRAMPLE_CLKGCFG_ACLK_GT_EN	(1 << 1)
#define WADDR_TRAMPLE_CLKGCFG_CFGCLK_GT_EN	(1 << 0)

#define AWADDR_TRAMPLE_EN				0x04
#define AWADDR_TRAMPLE_EN_BIT			(1 << 0)

#define AWADDR_TRAMPLE_TCAM_CTRL			0x08
#define AWADDR_TRAMPLE_TCAM_CTRL_TEST_MASK	(3 << 22)
#define AWADDR_TRAMPLE_TCAM_CTRL_T_SEL_MASK	(3 << 20)
#define AWADDR_TRAMPLE_TCAM_CTRL_MASK		(0xFFFFF)
#define AWADDR_TRAMPLE_TCAM_CTRL_SHIFT		(5)

#define AWADDR_TRAMPLE_STATUS				0x10
#define AWADDR_TRAMPLE_STATUS_RINT_CNT		(0xf << AWADDR_TRAMPLE_STATUS_RINT_CNT_SHIFT)
#define AWADDR_TRAMPLE_STATUS_RINT_CNT_SHIFT	4
#define AWADDR_TRAMPLE_STATUS_RINT_RINT_ST	(1 << 0)

#define AWADDR_TRAMPLE_AWMID				0x14
#define AWADDR_TRAMPLE_AWMID_VALUE		(0x1f << 0)

#define AWADDR_TRAMPLE_AWADDR				0x18
#define AWADDR_TCAM_MBIST_CTRL				0x1C
#define AWADDR_TCAM_MBIST_CTRL_MBIST_ERR_CMP	(1 << 6)
#define AWADDR_TCAM_MBIST_CTRL_MBIST_ERR_MEM	(1 << 5)
#define AWADDR_TCAM_MBIST_CTRL_MBIST_DONE	(1 << 4)
#define AWADDR_TCAM_MBIST_CTRL_MBIST_EN	(1 << 0)

#define AWADDR_TRAMPLE_MID_TBL				0x20
#define AWADDR_TRAMPLE_ITEMS				0x800
#define AWADDR_TRAMPLE_ITEMS_ENABLE		(1 << 30)
#define AWADDR_TRAMPLE_ITEMS_MIDMASK		0x3FF
#define AWADDR_TRAMPLE_ITEMS_MID(_mid)		((_mid & AWADDR_TRAMPLE_ITEMS_MIDMASK) << 20)
#define AWADDR_TRAMPLE_ITEMS_ADDR(_addr)	(_addr & 0xFFFFF)

#define hiwp_read(_host, _reg) \
        readl((char *)_host->regbase + (_reg))

#define hiwp_write(_host, _value, _reg) \
        writel((_value), (char *)_host->regbase + (_reg))
       
#endif /* #define DDR_WATCHPOINT_H */