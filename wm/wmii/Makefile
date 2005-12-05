# $NetBSD: Makefile,v 1.4 2005/12/05 20:51:10 rillig Exp $
#

DISTNAME=	wmii-20051031
CATEGORIES=	wm x11
MASTER_SITES=	http://wmii.de/snaps/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmii.de/
COMMENT=	Modular and keyboard-friendly window manager

DEPENDS+=		9base-[0-9]*:../../sysutils/9base

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	post-patch
SUBST_FILES.vars=	cmd/wm/wmii rc/* cmd/wm/wmii.1
SUBST_SED.vars=		-e 's|CONFPREFIX|${PREFIX}/share/examples|g'
SUBST_SED.vars+=	-e 's|9PREFIX|${PREFIX}|g'

PKG_SYSCONFSUBDIR=	wmii-3
EGDIR=			${PREFIX}/share/examples/wmii-3
EGFILES=		_clabel extern progmenu rcmenu status	\
			wmirc _plabel kmode quit rmpg welcome
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
