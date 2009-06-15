# $NetBSD: Makefile,v 1.7 2009/06/15 22:38:45 sno Exp $

DISTNAME=	Catalyst-Plugin-Authentication-0.10012
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Authentication/
COMMENT=	Infrastructure plugin for the Catalyst authentication framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=   	p5-Catalyst-Plugin-Session>=0.10:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-Catalyst-Runtime-[0-9]*:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

BUILD_DEPENDS+=	p5-Catalyst-Plugin-Session-State-Cookie-[0-9]*:../../www/p5-Catalyst-Plugin-Session-State-Cookie
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-MockObject>=0:../../devel/p5-Test-MockObject
BUILD_DEPENDS+=	p5-Test-WWW-Mechanize-Catalyst>=0.50:../../www/p5-Test-WWW-Mechanize-Catalyst

PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=	auto/Catalyst/Plugin/Authentication/.packlist
PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
