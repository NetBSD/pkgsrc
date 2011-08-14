# $NetBSD: Makefile,v 1.2 2011/08/14 15:28:44 obache Exp $

DISTNAME=	Convert-NLS_DATE_FORMAT-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-NLS_DATE_FORMAT/
COMMENT=	Convert Oracle NLS_DATE_FORMAT <-> strftime Format Strings
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	#empty
PERL5_PACKLIST= auto/Convert/NLS_DATE_FORMAT/.packlist

#post-extract:
#	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
