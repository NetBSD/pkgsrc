# $NetBSD: Makefile,v 1.2 1999/11/21 16:14:18 tron Exp $

DISTNAME=	pygtk-0.6.3
PKGNAME=	py-gtk-0.6.3
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/python/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/pygtk/

DEPENDS+=	libglade-*:../../devel/libglade
DEPENDS+=	python-*:../../lang/python

GNU_CONFIGURE=	yes
USE_X11=	yes
USE_GMAKE=	yes

.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == a.out)
post-configure:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.old
	${SED} -e 's#-Wl,-R#-R#g' ${WRKSRC}/Makefile.old >${WRKSRC}/Makefile
.endif

.include "../../mk/bsd.pkg.mk"
