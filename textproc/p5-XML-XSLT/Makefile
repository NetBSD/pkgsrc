# $NetBSD: Makefile,v 1.11 2004/12/20 11:31:11 grant Exp $

DISTNAME=	XML-XSLT-0.48
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxs
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jstowe/XML-XSLT-0.48/
COMMENT=	Perl5 module for processing XSLT

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/XSLT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
