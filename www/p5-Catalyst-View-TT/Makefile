# $NetBSD: Makefile,v 1.11 2011/08/14 16:05:51 obache Exp $

DISTNAME=	Catalyst-View-TT-0.35
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-TT/
COMMENT=	Template Toolkit view class for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.7000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class-[0-9]*:../../devel/p5-Path-Class
DEPENDS+=	p5-Template-Toolkit-[0-9]*:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Timer-[0-9]*:../../www/p5-Template-Timer

# for test target
BUILD_DEPENDS+=	p5-Template-Provider-Encoding-[0-9]*:../../www/p5-Template-Provider-Encoding

USE_LANGUAGES=		# empty
PERL5_PACKLIST= 	auto/Catalyst/View/TT/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
