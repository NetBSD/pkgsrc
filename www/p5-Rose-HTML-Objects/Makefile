# $NetBSD: Makefile,v 1.26 2017/06/05 14:25:30 ryoon Exp $

DISTNAME=	Rose-HTML-Objects-0.623
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-HTML-Objects/
COMMENT=	Object-oriented interfaces for HTML
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Clone-PP-[0-9]*:../../devel/p5-Clone-PP
DEPENDS+=	p5-DateTime>=0.20:../../time/p5-DateTime
DEPENDS+=	p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
#DEPENDS+=	{perl>=5.10,p5-Encode-[0-9]*}:../../textproc/p5-Encode
DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-IO-String>=1.08:../../devel/p5-IO-String
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils>=0}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Rose-DateTime>=0.532:../../time/p5-Rose-DateTime
DEPENDS+=	p5-Rose-Object>=0.85.4:../../devel/p5-Rose-Object
DEPENDS+=	p5-Rose-URI>=0.021:../../www/p5-Rose-URI
#DEPENDS+=	{perl>=5.10,p5-Scalar-List-Utils-[0-9]*}:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

# For tests:
BUILD_DEPENDS+=	p5-Test-Memory-Cycle-[0-9]*:../../devel/p5-Test-Memory-Cycle

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Rose/HTML/Objects/.packlist

post-extract:
	${FIND} ${WRKSRC} -name "*.pm" -type f -exec ${CHMOD} -x {} \;

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
