# $NetBSD: Makefile,v 1.3 2009/04/29 22:38:35 sno Exp $

DISTNAME=	Catalyst-View-Mason-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::View::Mason
COMMENT=	HTML::Mason view class for Catalyst
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-HTML-Mason>=0:../../www/p5-HTML-Mason
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Mason/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
