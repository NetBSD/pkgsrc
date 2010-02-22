# $NetBSD: Makefile,v 1.3 2010/02/22 14:01:03 sno Exp $

DISTNAME=	podlators-2.3.1
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/podlators/
COMMENT=	Collection of pod related perl modules
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Pod-Simple>=3.06:../../textproc/p5-Pod-Simple

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Pod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
