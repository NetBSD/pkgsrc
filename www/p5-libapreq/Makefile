# $NetBSD: Makefile,v 1.11 2005/02/23 19:04:09 wiz Exp $

DISTNAME=	libapreq-1.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}${PERL5_SITEARCH}/auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
