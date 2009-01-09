# $NetBSD: Makefile,v 1.3.2.1 2009/01/09 10:45:16 tron Exp $

DISTNAME=	Rose-HTML-Objects-0.600
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Rose-HTML-Objects/
COMMENT=	Object-oriented interfaces for HTML

DEPENDS+=	p5-DateTime>=0.20:../../time/p5-DateTime
DEPENDS+=	p5-Clone-PP>=0:../../devel/p5-Clone-PP
DEPENDS+=	p5-Encode>=0:../../textproc/p5-Encode
DEPENDS+=	p5-Email-Valid>=0:../../mail/p5-Email-Valid
DEPENDS+=	p5-HTML-Parser>=0:../../www/p5-HTML-Parser
DEPENDS+=	p5-Image-Size>=0:../../graphics/p5-Image-Size
DEPENDS+=	p5-URI>=0:../../www/p5-URI
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils
DEPENDS+=	p5-Rose-Object>=0.85.4:../../devel/p5-Rose-Object
DEPENDS+=	p5-Rose-DateTime>=0.532:../../time/p5-Rose-DateTime
DEPENDS+=	p5-Rose-URI>=0.021:../../www/p5-Rose-URI

USE_LANGUAGES=	# empty
PERL5_PACKLIST=		auto/Rose/HTML/Objects/.packlist

PKG_DESTDIR_SUPPORT=    user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
