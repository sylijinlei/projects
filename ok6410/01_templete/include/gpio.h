#ifndef _GPIO_H
#define _GPIO_H

#define PA_GPIO        0x7F008000
#define GPIOREG(reg)	(PA_GPIO + (reg))

#define GPA_BASE	GPIOREG(0x0000)
#define GPB_BASE	GPIOREG(0x0020)
#define GPC_BASE	GPIOREG(0x0040)
#define GPD_BASE	GPIOREG(0x0060)
#define GPE_BASE	GPIOREG(0x0080)
#define GPF_BASE	GPIOREG(0x00A0)
#define GPG_BASE	GPIOREG(0x00C0)
#define GPH_BASE	GPIOREG(0x00E0)
#define GPI_BASE	GPIOREG(0x0100)
#define GPJ_BASE	GPIOREG(0x0120)
#define GPK_BASE	GPIOREG(0x0800)
#define GPL_BASE	GPIOREG(0x0810)
#define GPM_BASE	GPIOREG(0x0820)
#define GPN_BASE	GPIOREG(0x0830)
#define GPO_BASE	GPIOREG(0x0140)
#define GPP_BASE	GPIOREG(0x0160)
#define GPQ_BASE	GPIOREG(0x0180)

#define GPACON			(GPA_BASE + 0x00)
#define GPADAT			(GPA_BASE + 0x04)
#define GPAPUD			(GPA_BASE + 0x08)
#define GPACONSLP		(GPA_BASE + 0x0c)
#define GPAPUDSLP		(GPA_BASE + 0x10)
#define GPA_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPA_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPA_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPBCON			(GPB_BASE + 0x00)
#define GPBDAT			(GPB_BASE + 0x04)
#define GPBPUD			(GPB_BASE + 0x08)
#define GPBCONSLP		(GPB_BASE + 0x0c)
#define GPBPUDSLP		(GPB_BASE + 0x10)
#define GPB_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPB_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPB_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPCCON			(GPC_BASE + 0x00)
#define GPCDAT			(GPC_BASE + 0x04)
#define GPCPUD			(GPC_BASE + 0x08)
#define GPCCONSLP		(GPC_BASE + 0x0c)
#define GPCPUDSLP		(GPC_BASE + 0x10)

#define GPC_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPC_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPC_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPDCON			(GPD_BASE + 0x00)
#define GPDDAT			(GPD_BASE + 0x04)
#define GPDPUD			(GPD_BASE + 0x08)
#define GPDCONSLP		(GPD_BASE + 0x0c)
#define GPDPUDSLP		(GPD_BASE + 0x10)

#define GPD_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPD_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPD_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPECON			(GPE_BASE + 0x00)
#define GPEDAT			(GPE_BASE + 0x04)
#define GPEPUD			(GPE_BASE + 0x08)
#define GPECONSLP		(GPE_BASE + 0x0c)
#define GPEPUDSLP		(GPE_BASE + 0x10)

#define GPE_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPE_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPE_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPFCON			(GPF_BASE + 0x00)
#define GPFDAT			(GPF_BASE + 0x04)
#define GPFPUD			(GPF_BASE + 0x08)
#define GPFCONSLP		(GPF_BASE + 0x0c)
#define GPFPUDSLP		(GPF_BASE + 0x10)

#define GPF_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPF_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPF_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPGCON			(GPG_BASE + 0x00)
#define GPGDAT			(GPG_BASE + 0x04)
#define GPGPUD			(GPG_BASE + 0x08)
#define GPGCONSLP		(GPG_BASE + 0x0c)
#define GPGPUDSLP		(GPG_BASE + 0x10)

#define GPG_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPG_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPG_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPHCON0			(GPH_BASE + 0x00)
#define GPHCON1			(GPH_BASE + 0x04)
#define GPHDAT			(GPH_BASE + 0x08)
#define GPHPUD			(GPH_BASE + 0x0c)
#define GPHCONSLP		(GPH_BASE + 0x10)
#define GPHPUDSLP		(GPH_BASE + 0x14)

#define GPH_CONMASK(__gpio)	(0xf << ((__gpio) * 4))
#define GPH_INPUT(__gpio)	(0x0 << ((__gpio) * 4))
#define GPH_OUTPUT(__gpio)	(0x1 << ((__gpio) * 4))

#define GPICON			(GPI_BASE + 0x00)
#define GPIDAT			(GPI_BASE + 0x04)
#define GPIPUD			(GPI_BASE + 0x08)
#define GPICONSLP		(GPI_BASE + 0x0c)
#define GPIPUDSLP		(GPI_BASE + 0x10)

#define GPI_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPI_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPI_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPJCON			(GPJ_BASE + 0x00)
#define GPJDAT			(GPJ_BASE + 0x04)
#define GPJPUD			(GPJ_BASE + 0x08)
#define GPJCONSLP		(GPJ_BASE + 0x0c)
#define GPJPUDSLP		(GPJ_BASE + 0x10)

#define GPJ_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPJ_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPJ_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPKCON			(GPK_BASE + 0x00)
#define GPKCON1			(GPK_BASE + 0x04)
#define GPKDAT			(GPK_BASE + 0x08)
#define GPKPUD			(GPK_BASE + 0x0c)

#define GPK_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPK_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPK_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPLCON          (GPM_BASE + 0x00)
#define GPLDAT          (GPM_BASE + 0x04)
#define GPLPUD          (GPM_BASE + 0x08)

#define GPL_CONMASK(__gpio) (0x3 << ((__gpio) * 2))
#define GPL_INPUT(__gpio)   (0x0 << ((__gpio) * 2))
#define GPL_OUTPUT(__gpio)  (0x1 << ((__gpio) * 2))

#define GPMCON          (GPM_BASE + 0x00)
#define GPMDAT          (GPM_BASE + 0x04)
#define GPMPUD          (GPM_BASE + 0x08)

#define GPMCON_MASK(__gpio)   (0xf << ((__gpio) * 4))
#define GPMDAT_MASK(__gpio)   (0x01 << ((__gpio) * 1))
#define GPMPUD_MASK(__gpio)   (0x03 << ((__gpio) * 2))            


#define GPNCON			(GPN_BASE + 0x00)
#define GPNDAT			(GPN_BASE + 0x04)
#define GPNPUD			(GPN_BASE + 0x08)

#define GPN_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPN_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPN_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPOCON			(GPO_BASE + 0x00)
#define GPODAT			(GPO_BASE + 0x04)
#define GPOPUD			(GPO_BASE + 0x08)
#define GPOCONSLP		(GPO_BASE + 0x0c)
#define GPOPUDSLP		(GPO_BASE + 0x10)

#define GPO_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPO_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPO_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPPCON			(GPP_BASE + 0x00)
#define GPPDAT			(GPP_BASE + 0x04)
#define GPPPUD			(GPP_BASE + 0x08)
#define GPPCONSLP		(GPP_BASE + 0x0c)
#define GPPPUDSLP		(GPP_BASE + 0x10)

#define GPP_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPP_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPP_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#define GPQCON			(GPQ_BASE + 0x00)
#define GPQDAT			(GPQ_BASE + 0x04)
#define GPQPUD			(GPQ_BASE + 0x08)
#define GPQCONSLP		(GPQ_BASE + 0x0c)
#define GPQPUDSLP		(GPQ_BASE + 0x10)

#define GPQ_CONMASK(__gpio)	(0x3 << ((__gpio) * 2))
#define GPQ_INPUT(__gpio)	(0x0 << ((__gpio) * 2))
#define GPQ_OUTPUT(__gpio)	(0x1 << ((__gpio) * 2))

#endif