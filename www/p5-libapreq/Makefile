# $NetBSD: Makefile,v 1.14 2005/08/06 06:19:40 jlam Exp $

DISTNAME=	libapreq-1.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lap
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

PERL5_PACKLIST=	auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
