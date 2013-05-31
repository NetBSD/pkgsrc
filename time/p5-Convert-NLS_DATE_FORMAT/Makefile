# $NetBSD: Makefile,v 1.5 2013/05/31 12:42:24 wiz Exp $

DISTNAME=	Convert-NLS_DATE_FORMAT-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-NLS_DATE_FORMAT/
COMMENT=	Convert Oracle NLS_DATE_FORMAT <-> strftime Format Strings
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty
PERL5_PACKLIST= auto/Convert/NLS_DATE_FORMAT/.packlist

#post-extract:
#	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
