# $NetBSD: Makefile,v 1.3 2009/05/01 12:22:47 sno Exp $

DISTNAME=	Catalyst-Plugin-Static-Simple-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Catalyst/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Catalyst-Plugin-Static/
COMMENT=	Serve static files with Catalyst
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	p5-Catalyst-Runtime>=5.30:../../www/p5-Catalyst-Runtime
DEPENDS+=	p5-MIME-Types>=1.15:../../mail/p5-MIME-Types
DEPENDS+=	p5-MRO-Compat-[0-9]*:../../devel/p5-MRO-Compat

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Catalyst/Plugin/Static/Simple/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
