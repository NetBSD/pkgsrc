# $NetBSD: Makefile,v 1.6 2005/12/29 06:22:20 jlam Exp $
#

DISTNAME=	wmii-20051114
CATEGORIES=	wm x11
MASTER_SITES=	http://wmii.de/snaps/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmii.de/
COMMENT=	Modular and keyboard-friendly window manager

DEPENDS+=		9base-[0-9]*:../../sysutils/9base

NO_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	post-patch
SUBST_FILES.vars=	cmd/wm/wmii rc/* cmd/wm/wmii.1
SUBST_SED.vars=		-e 's|CONFPREFIX|${PREFIX}/share/examples|g'
SUBST_SED.vars+=	-e 's|9PREFIX|${PREFIX}|g'

PKG_SYSCONFSUBDIR=	wmii-3
EGDIR=			${PREFIX}/share/examples/wmii-3
EGFILES=		extern kmode quit status welcome wmirc
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
