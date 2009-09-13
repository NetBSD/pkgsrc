# $NetBSD: Makefile,v 1.4 2009/09/13 19:52:18 sno Exp $

DISTNAME=	Catalyst-View-TT-0.30
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-TT/
COMMENT=	Template Toolkit view class for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.7000:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Timer>=0:../../www/p5-Template-Timer
DEPENDS+=	p5-Template-Provider-Encoding-[0-9]*:../../www/p5-Template-Provider-Encoding

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/TT/.packlist
#PERL5_MODULE_TYPE=	Module::Install::Bundled
MAKE_PARAMS+=	--skipdeps

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
