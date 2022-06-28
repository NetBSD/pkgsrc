# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:25 wiz Exp $

DISTNAME=	HTML-Template-Pro-0.9510
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Template-Pro
COMMENT=	Perl/XS module to use HTML Templates from CGI scripts
LICENSE=	${PERL5_LICENSE} OR gnu-lgpl-v2.1

DEPENDS+=	p5-JSON>=2.0:../../converters/p5-JSON

USE_LANGUAGES=	c
PERL5_PACKLIST=	auto/HTML/Template/Pro/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
