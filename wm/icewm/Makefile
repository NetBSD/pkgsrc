# $NetBSD: Makefile,v 1.2 2001/02/17 17:21:40 wiz Exp $
#

COMMENT=		small, fast and light-weight window manager

USE_XPM=		YES

CONFLICTS+=		icewm-gnome-[0-9]*

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"

.include "../../wm/icewm/Makefile.common"
