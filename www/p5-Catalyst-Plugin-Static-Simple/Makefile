# $NetBSD: Makefile,v 1.1.1.1 2008/07/15 09:30:29 abs Exp $

DISTNAME=	Catalyst-Plugin-Static-Simple-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Static/
COMMENT=	Serve static files with Catalyst

DEPENDS+=	p5-Catalyst-Runtime>=5.70:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MIME-Types>=1.15:../../mail/p5-MIME-Types

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Static/Simple/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
