#ifndef __SC3336_1L_CMOS_EX_H_
#define __SC3336_1L_CMOS_EX_H_

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#ifdef ARCH_CV182X
#include <linux/cvi_vip_cif.h>
#include <linux/cvi_vip_snsr.h>
#include "cvi_type.h"
#else
#include <linux/cif_uapi.h>
#include <linux/vi_snsr.h>
#include <linux/cvi_type.h>
#endif
#include "cvi_sns_ctrl.h"


enum sc3336_1l_linear_regs_e {
	LINEAR_EXP_H_ADDR,
	LINEAR_EXP_M_ADDR,
	LINEAR_EXP_L_ADDR,
	LINEAR_AGAIN_ADDR,
	LINEAR_DGAIN_H_ADDR,
	LINEAR_DGAIN_L_ADDR,
	LINEAR_VMAX_H_ADDR,
	LINEAR_VMAX_L_ADDR,
	LINEAR_REGS_NUM
};

typedef enum _SC3336_1L_MODE_E {
	SC3336_1L_MODE_2304X1296P20 = 0,
	SC3336_1L_MODE_LINEAR_NUM,
	SC3336_1L_MODE_2304X1296P20_WDR = SC3336_1L_MODE_LINEAR_NUM,
	SC3336_1L_MODE_NUM
} SC3336_1L_MODE_E;

typedef struct _SC3336_1L_MODE_S {
	ISP_WDR_SIZE_S astImg[2];
	CVI_FLOAT f32MaxFps;
	CVI_FLOAT f32MinFps;
	CVI_U32 u32HtsDef;
	CVI_U32 u32VtsDef;
	SNS_ATTR_S stExp[2];
	SNS_ATTR_S stAgain[2];
	SNS_ATTR_S stDgain[2];
	char name[64];
} SC3336_1L_MODE_S;

/****************************************************************************
 * external variables and functions                                         *
 ****************************************************************************/

extern ISP_SNS_STATE_S *g_pastSC3336_1L[VI_MAX_PIPE_NUM];
extern ISP_SNS_COMMBUS_U g_aunSC3336_1L_BusInfo[];
extern CVI_U16 g_au16SC3336_1L_GainMode[];
extern CVI_U16 g_au16SC3336_1L_L2SMode[];
extern CVI_U8 sc3336_1l_i2c_addr;
extern const CVI_U32 sc3336_1l_addr_byte;
extern const CVI_U32 sc3336_1l_data_byte;
extern void sc3336_1l_mirror_flip(VI_PIPE ViPipe, ISP_SNS_MIRRORFLIP_TYPE_E eSnsMirrorFlip);
extern void sc3336_1l_init(VI_PIPE ViPipe);
extern void sc3336_1l_exit(VI_PIPE ViPipe);
extern void sc3336_1l_standby(VI_PIPE ViPipe);
extern void sc3336_1l_restart(VI_PIPE ViPipe);
extern int  sc3336_1l_write_register(VI_PIPE ViPipe, int addr, int data);
extern int  sc3336_1l_read_register(VI_PIPE ViPipe, int addr);
extern int  sc3336_1l_probe(VI_PIPE ViPipe);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */


#endif /* __SC3336_1L_CMOS_EX_H_ */
