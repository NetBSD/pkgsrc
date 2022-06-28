# $NetBSD: Makefile,v 1.16 2022/06/28 11:37:28 wiz Exp $

DISTNAME=	HTTP-Headers-Fast-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTTP-Headers-Fast
COMMENT=	Perl extension for faster implementation of HTTP::Headers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date>0:../../www/p5-HTTP-Date
BUILD_DEPENDS=	p5-Test-Requires>0:../../devel/p5-Test-Requires

PERL5_MODULE_TYPE=	Module::Build::Tiny
PERL5_PACKLIST=		auto/HTTP/Headers/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
