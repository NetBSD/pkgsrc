# $NetBSD: Makefile,v 1.1.1.1 2000/05/30 12:46:19 rh Exp $
#

DISTNAME=	gateway-0.8
PKGNAME=	kannel-0.8
CATEGORIES=	FILLTHISINPLEASE
MASTER_SITES=	http://www.kannel.org/download/0.8/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org/

DEPENDS+=	libxml>=1.8.7:../../textproc/libxml
DEPENDS+=	pth>=1.3.5:../../devel/pth

USE_PERL5=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	CFLAGS="${CFLAGS} -I${PREFIX}/include"
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include"
CONFIGURE_ARGS+=--disable-docs

.include "../../mk/bsd.pkg.mk"
