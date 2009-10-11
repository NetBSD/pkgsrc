# $NetBSD: Makefile,v 1.19 2009/10/11 08:11:55 sno Exp $
#

DISTNAME=	TimeDate-1.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 TimeDate distribution
HOMEPAGE=	http://search.cpan.org/dist/TimeDate/
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/TimeDate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
