# $NetBSD: plist.mk,v 1.1.1.1 2005/01/26 16:15:46 cube Exp $

.include "../../mk/bsd.prefs.mk"

PERL5_MAN3DIR!=	eval `${PERL5} -V:installsiteman3dir 2>/dev/null`;	\
		${ECHO} $${installsiteman3dir}
PLIST_SUBST+=	PERL5_MAN3DIR=${PERL5_MAN3DIR:S/^${PREFIX}\///}
