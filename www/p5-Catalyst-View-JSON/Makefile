# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:30:58 abs Exp $

DISTNAME=	Catalyst-View-JSON-0.24
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Catalyst::View::JSON
COMMENT=	JSON view for your data in Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.60:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-JSON>=0:../../converters/p5-JSON
DEPENDS+=	p5-JSON-Any>=1.15:../../converters/p5-JSON-Any

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/View/JSON/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
