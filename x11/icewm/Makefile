# $NetBSD: Makefile,v 1.9 2000/08/23 23:14:36 tron Exp $
#

USE_XPM=		YES

CONFLICTS+=		icewm-gnome-[0-9]*

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"

.include "../../x11/icewm/Makefile.common"
