# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:31:13 abs Exp $

DISTNAME=	Catalyst-View-TT-0.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-View-TT/
COMMENT=	Template Toolkit view class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Template-Toolkit>=0:../../www/p5-Template-Toolkit
DEPENDS+=	p5-Template-Timer>=0:../../www/p5-Template-Timer
DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/TT/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
