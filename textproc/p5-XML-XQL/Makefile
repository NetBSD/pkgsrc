# $NetBSD: Makefile,v 1.4 2001/10/18 15:20:45 veego Exp $
#

DISTNAME=	XML-XQL-0.66
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xxq
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	packages@netbsd.org
COMMENT=	Perl module to perform XQL queries on XML object trees

DEPENDS+=	p5-XML-DOM-[0-9]*:../p5-XML-DOM
DEPENDS+=	p5-XML-Parser-2.*:../p5-XML-Parser
DEPENDS+=	p5-Date-Manip-[0-9]*:../../devel/p5-Date-Manip

CONFLICTS+=	p5-libxml-enno-[0-9]*

USE_PERL5=	yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/XQL/.packlist

do-configure:
		@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
