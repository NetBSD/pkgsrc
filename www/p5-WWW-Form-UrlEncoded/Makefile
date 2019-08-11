# $NetBSD: Makefile,v 1.8 2019/08/11 13:25:04 wiz Exp $

DISTNAME=	WWW-Form-UrlEncoded-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Form-UrlEncoded
COMMENT=	Parser and builder for application/x-www-form-urlencoded
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-JSON-PP>=2.0:../../converters/p5-JSON-PP

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/WWW/Form/UrlEncoded/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
