# $NetBSD: Makefile,v 1.13 2022/06/28 11:37:46 wiz Exp $

DISTNAME=	WWW-Form-UrlEncoded-0.26
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/WWW-Form-UrlEncoded
COMMENT=	Parser and builder for application/x-www-form-urlencoded
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/WWW/Form/UrlEncoded/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
