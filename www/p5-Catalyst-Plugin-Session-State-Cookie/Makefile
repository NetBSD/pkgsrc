# $NetBSD: Makefile,v 1.7 2009/06/11 12:06:12 abs Exp $

DISTNAME=	Catalyst-Plugin-Session-State-Cookie-0.11
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-State-Cookie/
COMMENT=	Maintain session IDs using cookies

DEPENDS+=	p5-Catalyst-Runtime>=5.7010:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Catalyst-Plugin-Session>=0.19:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-MRO-Compat>=0:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Test-MockObject>=1.01:../../devel/p5-Test-MockObject

PERL5_PACKLIST= auto/Catalyst/Plugin/Session/State/Cookie/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
