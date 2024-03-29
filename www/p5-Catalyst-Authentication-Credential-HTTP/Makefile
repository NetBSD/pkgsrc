# $NetBSD: Makefile,v 1.24 2023/07/06 09:42:25 wiz Exp $

DISTNAME=	Catalyst-Authentication-Credential-HTTP-1.018
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Catalyst-Authentication-Credential-HTTP
COMMENT=	HTTP Basic and Digest authentication for Catalyst
LICENSE=	${PERL5_LICENSE}

EXTRACT_USING=	bsdtar

DEPENDS+=	p5-Catalyst-Plugin-Authentication>=0.10008:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Data-UUID>=0.11:../../devel/p5-Data-UUID
DEPENDS+=	p5-String-Escape-[0-9]*:../../devel/p5-String-Escape
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

TOOL_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TOOL_DEPENDS+=	p5-Test-Needs-[0-9]*:../../devel/p5-Test-Needs
TOOL_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
TOOL_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

PERL5_PACKLIST=		auto/Catalyst/Authentication/Credential/HTTP/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
