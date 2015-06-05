# $NetBSD: Makefile,v 1.1 2015/06/05 12:53:01 wen Exp $

DISTNAME=	HTTP-Headers-Fast-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTTP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTTP-Headers-Fast/
COMMENT=	Perl extension for faster implementation of HTTP::Headers
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTTP-Date>0:../../www/p5-HTTP-Date
BUILD_DEPENDS=	p5-Test-Requires>0:../../devel/p5-Test-Requires

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/HTTP/Headers/Fast/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
