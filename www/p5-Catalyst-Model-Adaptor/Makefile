# $NetBSD: Makefile,v 1.1.1.1 2008/10/12 17:28:12 abs Exp $

DISTNAME=	Catalyst-Model-Adaptor-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/J/JR/JROCKWAY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::Model::Adaptor
COMMENT=	Use a plain class as a Catalyst model

DEPENDS+=	p5-Catalyst-Runtime>=0:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Class-C3>=0:../../devel/p5-Class-C3

BUILD_DEPENDS+=	p5-Test-Simple>=0:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-use-ok>=0:../../devel/p5-Test-use-ok

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Model/Adaptor/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
