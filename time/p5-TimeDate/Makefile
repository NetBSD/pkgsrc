# $NetBSD: Makefile,v 1.26 2013/07/10 03:01:57 schmonz Exp $
#

DISTNAME=	TimeDate-2.30
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tid
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 TimeDate distribution
HOMEPAGE=	http://search.cpan.org/dist/TimeDate/
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Date/Parse/.packlist

post-extract:
	cd ${WRKSRC};							\
	for f in Russian_cp1251.pm Russian_koi8r.pm Turkish.pm; do	\
	chmod -x lib/Date/Language/$${f};				\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
