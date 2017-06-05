# $NetBSD: Makefile,v 1.33 2017/06/05 14:25:35 ryoon Exp $

DISTNAME=	libapreq-1.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Apache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://httpd.apache.org/apreq/
COMMENT=	Lots of Apache specific httpd handling modules
LICENSE=	apache-2.0

MAKE_JOBS_SAFE=		no

DEPENDS+=	p5-Apache-Test>=1.13:../../www/p5-Apache-Test

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/libapreq/.packlist

LDFLAGS+=	${COMPILER_RPATH_FLAG}auto/libapreq

.include "../../lang/perl5/module.mk"
.include "../../www/ap2-perl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
