# $NetBSD: Makefile,v 1.9 2011/08/14 16:05:49 obache Exp $

DISTNAME=	Catalyst-Plugin-Session-Store-Delegate-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Session-Store-Delegate/
COMMENT=	Delegate session storage to an application model object
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Plugin-Session>=0.27:../../www/p5-Catalyst-Plugin-Session
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Emulate-Class-Accessor-Fast-[0-9]*:../../devel/p5-MooseX-Emulate-Class-Accessor-Fast
DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

BUILD_DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Session/Store/Delegate/.packlist
PERL5_MODULE_TYPE=	Module::Install

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
