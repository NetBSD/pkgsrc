# $NetBSD: Makefile,v 1.33 2017/06/05 14:25:07 ryoon Exp $
#

DISTNAME=	TimeDate-2.30
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 TimeDate distribution
HOMEPAGE=	http://search.cpan.org/dist/TimeDate/
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Date/Parse/.packlist

post-extract:
	cd ${WRKSRC};							\
	for f in Russian_cp1251.pm Russian_koi8r.pm Turkish.pm; do	\
	chmod a-x lib/Date/Language/$${f};				\
	done

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
