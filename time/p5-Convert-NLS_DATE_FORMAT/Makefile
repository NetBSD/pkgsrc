# $NetBSD: Makefile,v 1.20 2023/07/06 09:42:09 wiz Exp $

DISTNAME=	Convert-NLS_DATE_FORMAT-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-NLS_DATE_FORMAT
COMMENT=	Convert Oracle NLS_DATE_FORMAT <-> strftime Format Strings
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty
PERL5_PACKLIST=	auto/Convert/NLS_DATE_FORMAT/.packlist

PERL5_MODULE_TYPE=	Module::Build::Tiny

#post-extract:
#	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
