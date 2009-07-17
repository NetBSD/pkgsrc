# $NetBSD: Makefile,v 1.8 2009/07/17 18:00:24 adrianp Exp $
#

DISTNAME=	PyX-0.9
PKGNAME=	${PYPKGPREFIX}-X-0.9
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pyx/}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	teTeX-bin-[0-9]*:../../print/teTeX3-bin

PYDISTUTILSPKG=	yes

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pyx.sourceforge.net/
COMMENT=	Package for the creation of PostScript and PDF files

CONF_FILES=	${PREFIX}/share/examples/PyX/pyxrc \
		${PKG_SYSCONFDIR}/pyxrc

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_MESSAGE.conf=	Fixing configuration files.
SUBST_FILES.conf=	setup.py
SUBST_SED.conf+=	-e "s|@PKG_SYSCONFDIR@|${PKG_SYSCONFDIR}|g"

INSTALLATION_DIRS=	share/examples/PyX

pre-install:
	${CP} ${WRKSRC}/pyxrc ${WRKSRC}/pyxrc.default

post-install:
	${CP} ${WRKSRC}/pyxrc ${DESTDIR}${PREFIX}/share/examples/PyX/pyxrc

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
