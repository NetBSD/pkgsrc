# $NetBSD: Makefile,v 1.11 2013/12/09 14:17:55 obache Exp $

DISTNAME=	Catalyst-View-Mason-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::View::Mason
COMMENT=	HTML::Mason view class for Catalyst
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Catalyst-Runtime>=5.50:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-HTML-Mason>=0:../../www/p5-HTML-Mason
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat
DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	{perl>=5.10.1,p5-parent-[0-9]*}:../../devel/p5-parent

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/Mason/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
