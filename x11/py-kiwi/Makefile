# $NetBSD: Makefile,v 1.20 2012/09/07 19:17:50 adam Exp $
#

DISTNAME=	kiwi-1.9.29
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/kiwi/1.9/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.async.com.br/projects/kiwi/
COMMENT=	Framework and a set of enhanced PyGTK widgets
LICENSE=	gnu-lgpl-v2.1 # or later

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		#none
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		msgfmt

SUBST_CLASSES+=		localedir
SUBST_STAGE.localedir=	pre-configure
SUBST_FILES.localedir=	setup.py
SUBST_SED.localedir=	-e 's|share/locale|${PKGLOCALEDIR}/locale|'

# tarball contains neither api nor howto.
post-install:
	rmdir ${DESTDIR}${PREFIX}/share/doc/kiwi/api || true
	rmdir ${DESTDIR}${PREFIX}/share/doc/kiwi/howto || true

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
BUILDLINK_API_DEPENDS.pygtk2+=	${PYPKGPREFIX}-gtk2>=2.18
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
