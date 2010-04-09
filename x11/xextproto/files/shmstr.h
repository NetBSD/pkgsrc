/* $NetBSD: shmstr.h,v 1.1 2010/04/09 08:33:38 tnn Exp $ */

#warning this file is deprecated and provided only for source compatibility

#include "shmproto.h"
 
#define XSHM_PUT_IMAGE_ARGS \
    DrawablePtr		/* dst */, \
    GCPtr		/* pGC */, \
    int			/* depth */, \
    unsigned int	/* format */, \
    int			/* w */, \
    int			/* h */, \
    int			/* sx */, \
    int			/* sy */, \
    int			/* sw */, \
    int			/* sh */, \
    int			/* dx */, \
    int			/* dy */, \
    char *		/* data */

#define XSHM_CREATE_PIXMAP_ARGS \
    ScreenPtr	/* pScreen */, \
    int		/* width */, \
    int		/* height */, \
    int		/* depth */, \
    char *	/* addr */

typedef struct _ShmFuncs {
    PixmapPtr	(* CreatePixmap)(XSHM_CREATE_PIXMAP_ARGS);
    void	(* PutImage)(XSHM_PUT_IMAGE_ARGS);
} ShmFuncs, *ShmFuncsPtr;
