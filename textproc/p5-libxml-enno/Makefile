# $NetBSD: Makefile,v 1.7 2001/11/29 13:27:47 jlam Exp $

DISTNAME=	libxml-enno-1.05a
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lxe
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	packages@NetBSD.org
HOMEPAGE=	http://www.erols.com/enno/
COMMENT=	Several XML manipulation tools, including XML::DOM

DEPENDS+=	p5-XML-Parser>=2.29:../../textproc/p5-XML-Parser
DEPENDS+=	p5-Date-Manip>=5.39:../../devel/p5-Date-Manip
DEPENDS+=	p5-libwww>=5.50:../../www/p5-libwww
DEPENDS+=	p5-libxml>=0.07:../../textproc/p5-libxml
DEPENDS+=	p5-Parse-Yapp>=1.04:../../devel/p5-Parse-Yapp

CONFLICTS+=	p5-XML-DOM-[0-9]* p5-XML-XQL-[0-9]*
CONFLICTS+=	p5-XML-Checker-[0-9]* p5-XML-RegExp-[0-9]*

WRKSRC=		${WRKDIR}/libxml-enno-1.05

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/libxml-enno/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
