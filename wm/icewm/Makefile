# $NetBSD: Makefile,v 1.1.1.1 2000/12/12 02:03:48 wiz Exp $
#

USE_XPM=		YES

CONFLICTS+=		icewm-gnome-[0-9]*

EVAL_PREFIX+=		XPMDIR=xpm
CONFIGURE_ARGS+=	--with-xpm="${XPMDIR}"

.include "../../wm/icewm/Makefile.common"
