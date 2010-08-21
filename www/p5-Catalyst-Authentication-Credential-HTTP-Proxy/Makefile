# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:38 seb Exp $

DISTNAME=	Catalyst-Authentication-Credential-HTTP-Proxy-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Authentication-Credential-HTTP-Proxy/
COMMENT=	HTTP Proxy authentication for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Authentication-Credential-HTTP>=1.009:../../www/p5-Catalyst-Authentication-Credential-HTTP
DEPENDS+=	p5-Catalyst-Plugin-Authentication-[0-9]*:../../www/p5-Catalyst-Plugin-Authentication
DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject

PERL5_PACKLIST= 	auto/Catalyst/Authentication/Credential/HTTP/Proxy/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
