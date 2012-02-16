# $NetBSD: Makefile,v 1.3 2012/02/16 19:54:38 hans Exp $
#

DISTNAME=	wbxml2-0.9.2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wbxmllib/}

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://wbxmllib.sourceforge.net/
COMMENT=	Library to handle WAP binary XML files

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	pkg-config
USE_TOOLS+=	aclocal autoheader automake autoconf
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes

PKGCONFIG_OVERRIDE+=	libwbxml2.pc.in

CPPFLAGS.SunOS+=	-std=c99 -D_XOPEN_SOURCE=600

pre-configure:
	cd ${WRKSRC} && \
		${PREFIX}/bin/libtoolize && \
		aclocal && \
		autoheader && \
		automake --add-missing && \
		autoconf

.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
