# $NetBSD: Makefile,v 1.32 2017/06/05 14:25:00 ryoon Exp $

DISTNAME=	XML-XSLT-0.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xmlxslt.sourceforge.net/
COMMENT=	Perl5 module for processing XSLT

DEPENDS+=	p5-XML-DOM>=1.25:../../textproc/p5-XML-DOM
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/XML/XSLT/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
