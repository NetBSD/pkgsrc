# $NetBSD: Makefile,v 1.11 2006/10/22 13:02:57 obache Exp $
#

DISTNAME=	wmii-2.5.2
CATEGORIES=	wm x11
MASTER_SITES=	http://suckless.org/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wmii.suckless.org/
COMMENT=	Modular and keyboard-friendly window manager

DEPENDS+=		9base-[0-9]*:../../sysutils/9base

NO_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

SUBST_CLASSES+=		vars pfx
SUBST_STAGE.vars=	post-patch
SUBST_FILES.vars=	cmd/wm/wmii rc/* cmd/wm/wmii.1
SUBST_SED.vars=		-e 's|CONFPREFIX|${PREFIX}/share/examples|g'
SUBST_SED.vars+=	-e 's|9PREFIX|${PREFIX}|g'

SUBST_STAGE.pfx = post-patch
SUBST_FILES.pfx = config.mk
SUBST_SED.pfx = -e s,/usr/local,${PREFIX},g
SUBST_SED.pfx+= -e 's|/usr/X11R6|${X11BASE}|g'
SUBST_SED.pfx+= -e 's|/usr/X11R6|${X11BASE}|g'
SUBST_SED.pfx+= -e 's|CFLAGS = -O0 -g -Wall|CFLAGS+=|g'
SUBST_SED.pfx+= -e 's|-g||g'
SUBST_SED.pfx+= -e 's|/9||g'
SUBST_SED.pfx+= -e 's|cc|${CC}|g'

PKG_SYSCONFSUBDIR=	wmii-3
EGDIR=			${PREFIX}/share/examples/wmii-3
EGFILES=		extern kmode quit status welcome wmirc
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
