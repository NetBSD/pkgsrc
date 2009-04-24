# $NetBSD: Makefile,v 1.2 2009/04/24 17:15:24 sno Exp $

DISTNAME=	Catalyst-View-Mason-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::View::Mason
COMMENT=	HTML::Mason view class for Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-HTML-Mason>=0:../../www/p5-HTML-Mason
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Mason/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
