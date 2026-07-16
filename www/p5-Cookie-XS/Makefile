# $NetBSD: Makefile,v 1.16 2026/07/16 19:05:53 wiz Exp $

DISTNAME=	Cookie-XS-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AG/AGENT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Cookie-XS
COMMENT=	HTTP Cookie parser in C (deprecated)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CGI-Cookie-XS>=0.15:../../www/p5-CGI-Cookie-XS

USE_LANGUAGES=	#
PERL5_PACKLIST=	auto/Cookie/XS/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
