# $NetBSD: Makefile,v 1.2 2017/02/01 13:31:52 mef Exp $

DISTNAME=	WWW-Form-UrlEncoded-0.23
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=WWW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/WWW-Form-UrlEncoded/
COMMENT=	Parser and builder for application/x-www-form-urlencoded
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-JSON-[0-9]*:../../converters/p5-JSON
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/WWW/Form/UrlEncoded/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
