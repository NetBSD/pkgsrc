# $NetBSD: Makefile,v 1.5 2001/06/11 06:34:55 jlam Exp $
#

DISTNAME=	gateway-0.8
PKGNAME=	kannel-0.8
CATEGORIES=	www net
MASTER_SITES=	http://www.kannel.org/download/0.8/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.kannel.org/
COMMENT=	open source WAP and SMS gateway

DEPENDS+=	libxml>=1.8.7:../../textproc/libxml
DEPENDS+=	pth>=1.3.5:../../devel/pth

USE_PERL5=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
CONFIGURE_ARGS+=--disable-docs

.include "../../mk/bsd.pkg.mk"
